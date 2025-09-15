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