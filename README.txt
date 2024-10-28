***MAKEFILE***

TO GET ALL THE SRCS *.C FILEPATHS FOR YOUR MAKEFILE: GO TO THE SRCS FOLDER IN TERMINAL AND TYPE:

(find . -type f -name "*.c" | sed 's|^\./|srcs/|') | xclip -selection clipboard

PASTE CLIPBOARD IN MAKEFILE.