# CUB3D

A 3D renderer coded **in pure C** based on the *raytracing* technique capable of parsing textures and color.

#### *example of valid map*
![not very fun, but works!](/assets/readme/cub0.jpg)

## Features

1. The window size is 1280x800, a 16:10 resolution used classically by Doom to use fewer pixels. It's a callback to the limitations of the time.
2. It uses raycasting, a way to calculate the color correspondent to each pixel by calculating the distance from our eye to the next obstacle.
3. Reads `.cub` maps composed of the following:
	- NO, WE, EA, SO texture paths
	- C and F colors in format 255,255,255
	- A map made out of:
		- 0s for floor
		- 1s for walls
		- N/S/E/W for player spawm

#### *example of valid map*
![example of valid map](/assets/readme/cub1.jpg)

#### *example of valid map*
![example of invalid map](/assets/readme/cub2.jpg)

## Considerations

On parsing error, there will inevitably be "still reachable" reports caused by the way 42 forces us to design the get_next_line.c function. They happen only on exit, not at runtime, so they are just ignored.

## The raycasting technique (freaks only)

Raycasting is the technique of "casting rays" to the world we are parsing to get
a value that tells us how far from our player a pixel is, so we can draw it
with a correspondant size. This gives us the illusion of perspective, and is
calculated taking into account several factors and the use of trigonometry and
vectors.

You need to ask yourself:
- What direction of the world am I looking in?
- How much of the world can I see from my eyes?
- What of the world itself am I seeing combining this two factors?
- To what pixels of my screen do each of these rendered pixels correspond?

### Direction

Vectors are (usually) pairs of values that indicate a direction.
If I have 4 posible directions (N, S, E, W), a vector is a combination of
2 of these (E/W, N/S).
“If you set N=1, S=-1, E=1, W=-1, a direction of (1, 0) would mean ‘looking East’; a direction of (0, -1) would mean ‘looking South’.”
Any direction in between these is calculated with sine and cosine.

### Trigonometry

If you try to put a direction vector in a carthesian X and Y graph, you
would have to draw an arrow starting from 0 in the desired direction instead
of a point somewhere in the graph.
This is easy to represent when you are in one of the axis, like (1,0).
But, what if we are looking somewhere in between N and E?
For that, you need to use the angle drawn by the direction between the
axes of the graph and apply some trigonometry operations.
Lets say we have a 26º angle:

Convert to radians:
	
	26 ∗ π / 180 ≈ 0.454

Compute cosine (the X component)

	cos(0.454) ≈ 0.899 	-> 	this is the result of a complicated operation
							we don't need to know, just use the math lib
Compute sine (the Y)

	sin(0.454) ≈ 0.438

Now you can represent your direction as (0.89, 0.43).

And all of this, what do we want it for then...?
Exactly: to know what in our world we are looking at.

### PoV

Now, how much of this world can I see through my eyes?
We now where we are directing our perspective; we need to find out the limits
of our vision.
This limit is going to be calculated tracing a perpendicular vector from the direction vector. We will say "from that direction, I wanna see N points to the left and to the right".

Lets say we've got the vector (0, 1), that's straight north. To get the PoV, we need to determine how many degrees from the center (center=direction) I want to be able to see to each side of that direction. Those maximums will be set thanks to a new vector we will trace perpendicularly to the direction vector: the plane vector.

To trace a perpendicular vector to another, you just need to swap the values and minus the y direction.

	data->player->plane_vector_x = -data->player->dir_y * 0.73;
	data->player->plane_vector_y = data->player->dir_x * 0.73;

The multiplying value is your personal manipulation of the PoV. It lets you make it bigger or smaller (scale). The bottomline is that exceding the 'dir_y' and 'dir_x' values will give you an unreal PoV, like a fish-eye lens.

Again, this vector doesn't gives us workable data by itself yet, but we will use it to calculate the final, usable values. Right now, we have just traced a vector pointing more or less 90º to the right of our direction vector. The final PoV will be an angle inside this perpendicular vector, starting from the forward (direction) vector. Without this vector, we wouldn't be able to calculate how much to the left or right we can see from the forward vector.

In any case, with these, we have the neccessary data to set our PoV, which in actually doesn't exist per se; the final PoV is just the amount of world in front of our player that we will print in the screen.

### Camera

Now we have a direction and a vector called plane to calculate what range of the world we want to print in the screen. But, how do I actually determine what needs to be printed? I know the range of things that I have to process, but I'm not storing those things anywhere. Also, how do I process that info into pixels my screen?

We are going to create a "camera". We are going to divide our screen in columns and translate its width into a range of values from -1 to 1.
That is called normalization: we use simple math values instead of the raw specific values, like -1200 to 1200.

Examples:

	2.0 * 0 / 1200 - 1.0 = -1.0 -> we draw in the '0th' column.

	2.0 * 150 / 1200 - 1.0 = -0.75 -> we draw in the '150th' column.

Also, this way we can set a left and a right side: -1 is the left edge , 0 is center, and 1 is the right edge.

**Rays and vector arithmetic**

Now we are going to set a third vector for each of the columns of our screen, the 'ray_dir' vector. This vector will point to a place in the world between the left and right edges set by our PoV calculation (the plane vector).

Adding up the plane and forward vectors would end up exactly in the right edge of the visible world. That's simple vector arithmetic, which is not like angle arithmetic. 

When you add up two vectors (90º and 180º, that's 0,1 and -1,0), you would think that the result is 170º. Actually, the result is (-1, 1), 135º. This is something we need to understand in order to know why we are doing what we are doing.

Remember we said that the PoV we calculated didn't set the edge of the visible world? That's because the actual PoV is calculated adding up the direction and PoV, or forward and plane vectors. And taking into account the vector arithmetic we just discussed, we end up with a curious result: a vector right in between them (like in the previous example).

This is called addition geometry.

So in practical therms, the angle of the PoV or plane vector gives us is not the angle of the visible PoV. Instead, we end up with half that value to the left from the center, and half to the right. 

We will take this in consideration for the next question: if adding up both vectors will result in a vector pointing to the right edge... how do we force it to start from the left and go to the right?

Because we want to send to each column of the window from left to right a proportional portion of the world, we need to iterate through every column and use that column position ('camera_x') to compute which part of the world we wanna fit into each column.

We normalized 'camera_x' to a range of values from -1 to 1. Multiplying the plane angle, which is the horizontal offset, by 'camera_x', will give us a resulting angle relative to the center (the forward vector), which is static unless we rotate. This way we will get vectors, "rays", from the very left to the very right.

Now we've got rays, we need to interpret what they are pointing to!

**Digital Differential Analyzer (DDA)**	

This is the algorithm we will use to calculate the distance between our player and the next renderable object. Is a series of set calculations used to measure distance inside of a grid of squares.

*Unit scales as map units*

To calculate the distance between player and an object to be projected (which is the only thing we must print, as the floor and ceiling are just plain colors), first we must declare a measuring unit.

Our only parameter available to determine distance up to this point is the grid of 0s and 1s in the .cube map. So the goal is to see how many "squares" each ray is crossing until it reaches a wall, taking into account we won't be crossing them in a perfect 45º angle only. Thus, we need a unit to measure this distance. Map units.

	void	set_cell_distance(t_cub3d_data *data)
	{
		if (data->dda->ray_dir_x == 0)
			data->dda->delta_dist_x = INFINITY;
		else
			data->dda->delta_dist_x = fabs(1.0 / data->dda->ray_dir_x);
		if (data->dda->ray_dir_y == 0)
			data->dda->delta_dist_y = INFINITY;
		else
			data->dda->delta_dist_y = fabs(1.0 / data->dda->ray_dir_y);
	}

For each cell a ray crosses and depending on the angle it is entering in the cell, we get a distance unit.

Depending on the angle of the ray we are casting, each time the ray crosses a row or a column of the map grid, we will travel a different distance. If it was a perfect 45º ray, each time the ray crosses a column or a row we will advance 1 world measure (lets say, 1 meter). But if we had a 85º ray, each time we crossed a row we'd travel ~1, and ~11.5 for a column. This is why we must update this measuring unit on each column.

This proportionallity is called the delta value.
	
*Setting up the ray starting point and direction*

Now we know the size of each step travelled by our ray, we will determine in which direction is advancing and from what point in the grid we will start calculating distance.

First, we need to know the direction. We use the 'ray_dir' vector for that.

Second, we need to find out how far away is the player from the grid lines, because we won't always be directly stepping the x or y axes! Because we know the delta values, we can use that to find out the exact point inside the cell the player's in. It's like Inception! A cell is a grid inside a bigger grid, which is the map.
We can find that the player is in the 0.3,0.7 point in the cell, so assuming our cells are 1x1, that means we are 0.7 points away from the next column, and 0.3 from the next row. Depending on which value is smaller, we will start calculating the ray distance from X or Y.

**Raytracing**

With all this, we are ready to calculate the distance.

Our loop will move us through the map grid until we reach a 1 value.
During each iteration, we will increment the 'side_dist' value to tell us how far is this wall from us, incrementing it by the delta values. That's why we needed to know where exactly inside the cell started (that calculation sets the initial value of this variable, so if we advance X times delta, we will end up with X + starting value).
We decide if advancing rows or columns depending on which line is closer to us in the next iteration: the y or the x.
Additionally, the function will store what direction is our wall facing by marking the 'side' combined with 'step_direction'. If our last move was in the X axis, we end up hitting a wall facing E or W.

*Perpendicular distance*

Something interesting happens when calculating the distance.

Imagine we are tracing a ray directly from 1.3 to cell 2.

	Cell 1       Cell 2
	|-------|-------|
			^
			| Player at x = 1.3

We calculate distance like 2 - 1.3 = 0.7
But what happens when we calculate the rays to the left?
The first value of the formula corresponds to the cell index we just stepped into. The problem is that landing in the edge of a left sided line counts as landing in the previous cell. Every cell starts counting as a cell from its left wall. But if we are inside cell 1, if we reach the left border of it, that counts as the end of cell 0. All of this means we are off by 1 in our calculation. 

	0 - 1.3 = -1.3 WRONG

With the used formula we can fix that offset.

((1 - step_x)/2) -> returns 1 or 0 to determine if we need the adjustment.

	1 + -1.3 = -0.3

This first adjustment is what gives us the correct render distances.

Now, if we'd use this raw value, we'd see a fish eye effect because we haven't taken into account the angle of the ray beign traced.

Dividing that "grid distance" (how far we are to a wall) by the correspondent component of the ray vector will calculate the hypotenuse of the triangle formed between the hit point, the distance to the wall and the player.

So, we do:

	final_distance = adjusted_distance / plane_vector

We are ready to draw.

*Setting up the wall*

The column slice beign drawn will be inversely proportional to the distance. This means the smaller the distance, the bigger the slice. Lets say the result is a slice of 300 in a total height of 600.

Now, we need the y index from where to start drawing, and where to finish.

The map is divided in 2 sections set by where we want to have the eye level, in this case, the most logical one: win_height / 2. The start is N above that, and the end is N below that.

That would mean:

	slice_height = 600 / 2 = 300
	draw_start = -150 + 300 = 150
	draw_end = 150 + 300 = 450

We clamp the pixels in case they exceed the limits, so if start < 0 = 0, and if => win_height = win_height - 1 because of the 0 index.

And, finally, we just need to map the texture to decide what color to send to the pixel!

*Texture and pixel put*

We will proceed to draw a vertical slice inside each column of the window. This means: we will iterate throughout the window, but will only put pixels in those that correspond to a pixel of a wall.
Right now, we know that in the current column of pixels, theres a wall slice that must be drawn. We know it's total height, that's been set by the distance between it and our player, as well as in what index of the column should start and end. Hence, to iterate through the slice:

	y = data->dda->draw_start;
	while (y <= data->dda->draw_end)

We are in the very top of the slice now, but, how do we know what slice of the texture corresponds to that position?

1. We find out the actual height of the slice.

	slice_height = data->win_height / data->dda->perp_wall_dist;

2. We get the position of 'x' inside the texture. First, we calculate the exact x (column) of the wall beign hit, which will be a value between 0 and 1. After that, is as simple as using that value to multiply it by the texture width. Voila, you got the matching x in the texture for the x in the wall. In the case of north and east walls, we flip them to match our PoV.

	For both the 'x' and 'y' position we include this part of the operation:

		... * 2) % data->dda->wall_texture->height;

	What that is doing is skipping every other pixel of the texture until it reaches the vertical or horizontal half of the wall, and then starting again (thanks to the modulo).

	Why? Because that way we get a mosaic of 4 textures for each wall instead of a giant texture filling up the whole side.

3. We calculate the sampling. We must figure out how to fit each texture of a fixed size into a wall of a variable size. Calculating the sampling we decide how many times we want to use each pixel of the texture for the current vertical slice. When exceding the size of the texture, you'll want to reuse pixels, and viceversa. It's as easy as dividing the texture height by the slice height.

4. We get the exact point we are in the texture's 'y' axis in order to select the appropiate color. Because we have a sampling value, we will move through the texture column in "sampling steps" instead of jumping from one index to the next. This will allow us to reuse or skip the pixels of the scale.

We now know: 
	- Where in the column of the window our slice starts.
	- The scale of our sampling.
	- What column of the texture matches with the column of the wall.
	- The exact color we must send first to the visible top of the slice.

The final steps will be to convert the bytes stored in memory in the selected index of the texture, translate that to BGR code using simple bit-shift arithmetics, and advance a sampling unit in the texture for each index of the slice.

We've got walls. Texturized walls.
