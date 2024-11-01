***MAKEFILE***

TO GET ALL THE SRCS *.C FILEPATHS FOR YOUR MAKEFILE: GO TO THE SRCS FOLDER IN TERMINAL AND TYPE:

(find . -type f -name "*.c" | sed 's|^\./|srcs/|') | xclip -selection clipboard

PASTE CLIPBOARD IN MAKEFILE.


***GIT***

CREATE REPOSITORY
...
//TO ACCESS A BRANCH
	git checkout -b <BRANCH_NAME>
	code .
// DO SOME CODING
	git add .
	git commit -m "custom message"
	git push -u origin <BRANCH_NAME>
// GO BACK TO MASTER
	git checkout master
	git pull
