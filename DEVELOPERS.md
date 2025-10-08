Github workflow

	Our project has a <main> branch that is always production ready, stable and open to the public. At any given time, somebody can use this code, compile and run without problems (that we know of). It might not have all the features yet, nor be pretty, but it works.

	On the other hand, we use a <develop> branch which we use to integrate the different features we want to add in. This way, we can test how the code works with the rest without risking messing up the production ready <main> branch.

		Create <develop> branch from <main>:

			git checkout main
			git pull origin main
			git checkout -b develop
			git push -u origin develop

			"-u origin" it's used on the first push to indicate literally to what remote repository we are pushing this new branch. "-u" means upstream, and "origin" is an alias for the address of the repository.

	We create branches from <develop> designated exclusively to the part we are developing.

		Create "feature/feature_name" branch from develop:

			git checkout develop
			git pull origin develop
			git checkout -b feature/feature_name

		Push changes to branch for the first time:

			git add .
			git commit -m "feat: add login page layout"
			git push -u origin feature/login-page

			After the first time, "-u origin" is no longer needed

		We use the following naming conventions:

			- New features: "feature/feature_name"
			- Bugs: "bugfix/bug_name"

	For errors in the production branch we operate in a branch created from <main>
	called "hotfix/error_name".

	We commit regularly every piece of the feature to the branch.

		- Our commits are like this: "feature: add opening window"
		- The rule of thumb is building something whose description takes just a little line.

	When the full feature is done is when we push to the branch. Then, we open a Pull Request (PR) into develop.

		To make a pull request, you go to your Github repo and click on the <Pull requests> tab. <New pull request>. The left branch is the one we will merge into, the right is the one that will be merged. <Create pull request>. Type the description of the changes. <Create pull request> again. It will check for conflicts and will be available for reviewing. 
		
		For reviewing, there is a comment box where you can type in your inputs.


	We run authomatic testing in the branch to see if it works. We use Github Actions defined in our ".github\workflows" folder. We could also authomate integrations like pushing up to a server the latest hotfix if we so needed it. This proccess is called CI/CD as in "continuous integration/continuous deployment".

		- First, Make sure Makefile is updated to include the files you have created.

		- Our current CI includes:

			- Compiling the project with our 42 flags.
			- Running the project
			- norminette check
		
	After review, test and aproval, we rebase if required, and then merge with the <develop> branch.

		- "rebase" puts our commit history on top of the target branch in case we are behind it.

	If there were merging conflicts, it's as easy as going through each file accepting either the current code or the incoming one (incoming changes). Those messages will be prompted authomatically. Then, git add . && git commit to confirm those conflicts.

Valgrind

	Use this command:

	valgrind --suppressions=mlx.supp --show-leak-kinds=all --leak-check=full --track-fds=yes --trace-children=yes --track-origins=yes ./cub3d map_test.cub

Roadmap

	1. Player & Camera Setup

	Define a player struct with:

	Position (x, y) in map coordinates.

	Direction vector (dir_x, dir_y).

	Plane vector (plane_x, plane_y) for camera plane (controls FOV).

	Initialize starting position based on your parsed map.

	2. Raycasting Loop

	For each vertical screen column x:

	Calculate ray direction based on camera plane.

	Determine which square of the map the ray is in.

	Step through the grid using DDA (Digital Differential Analysis) to find the first wall hit.

	Calculate distance to wall to correct fisheye effect.

	Determine line height on screen to draw the wall slice.

	Draw vertical lines representing walls with different colors based on wall orientation (optional shading).

	3. Rendering

	Draw floor and ceiling (can be a solid color or textured later).

	Draw wall slices column by column.

	Update the window each frame (double buffering with mlx_put_image_to_window recommended).

	4. Movement & Controls

	Add keyboard input to:

	Move forward/backward.

	Strafe left/right.

	Rotate left/right.

	Update player position with collision detection (don’t let the player go through walls).

	5. Optional Enhancements

	Textures: Map walls to texture images, scale vertical slice according to distance.

	Sprites: Add objects like enemies or pickups using depth sorting.

	Lighting/Shading: Darker walls farther away, or face-based shading.

	6. Optimization

	Avoid recalculating constants inside loops.

	Limit resolution for faster rendering (scale up after testing).



Features

	- Cambiar tamano muros + pov con fog
	- Mejora de rendimiento con gettimeofday para controlar los frames del juego
	- Implementar pantalla de carga y de bienvenida
	- 