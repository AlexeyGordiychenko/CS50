# [Week 4](../../README.md)

## Lab

---
### [*Smiley*](smiley/colorize.c)

Learning Goals
- Learn how to work with images
- Practice manipulating pixels

Open up `helpers.c` and notice that the `colorize` function is incomplete. Note that the image’s height, width and a two-dimensional array of pixels is set up as the input parameters for this function. You are to implement this function to change all the black pixels in the image to a color of your choosing.

Your program should behave per the examples below.

```
smiley/ $ ./colorize smiley.bmp smiley_out.bmp
```

When your program is working correctly, you should see a new file, `smiley_out.bmp` in your `smiley` directory. Open it up and see if the black pixels are now the color you’ve specified.

---
### [*Volume*](volume.c)

Complete the implementation of `volume.c`, such that it changes the volume of a sound file by a given factor.

- The program accepts three command-line arguments: `input` represents the name of the original audio file, `output` represents the name of the new audio file that should be generated, and `factor` is the amount by which the volume of the original audio file should be scaled.
  - For example, if `factor` is `2.0`, then your program should double the volume of the audio file in `input` and save the newly generated audio file in `output`.
- Your program should first read the header from the input file and write the header to the output file. Recall that this header is always exactly 44 bytes long.
  - Note that `volume.c` already defines a variable for you called `HEADER_SIZE`, equal to the number of bytes in the header.
- Your program should then read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time. Your program should multiply each sample by the `factor` and write the new sample to the output file.
  - You may assume that the WAV file will use 16-bit signed values as samples. In practice, WAV files can have varying numbers of bits per sample, but we’ll assume 16-bit samples for this lab.
- Your program, if it uses `malloc`, must not leak any memory.

Your program should behave per the examples below.

```
$ ./volume input.wav output.wav 2.0
```
When you listen to `output.wav` (as by control-clicking on `output.wav` in the file browser, choosing Download, and then opening the file in an audio player on your computer), it should be twice as loud as `input.wav`!

```
$ ./volume input.wav output.wav 0.5
```
When you listen to `output.wav`, it should be half as loud as `input.wav`!

## Problem Set

---
### [*Filter*](filter-more/filter.c)

Implement the functions in `helpers.c` such that a user can apply grayscale, reflection, blur, or edge detection filters to their images.

- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
- The `reflect` function should take an image and reflect it horizontally.
- The `blur` function should take an image and turn it into a box-blurred version of the same image.
- The `edges` function should take an image and highlight the edges between objects, according to the Sobel operator.

You should not modify any of the function signatures, nor should you modify any other files other than `helpers.c`.

Your program should behave per the examples below. INFILE.bmp is the name of the input image and OUTFILE.bmp is the name of the resulting image after a filter has been applied.

```
$ ./filter -g INFILE.bmp OUTFILE.bmp
```
```
$ ./filter -r INFILE.bmp OUTFILE.bmp
```
```
$ ./filter -b INFILE.bmp OUTFILE.bmp
```
```
$ ./filter -e INFILE.bmp OUTFILE.bmp
```

---
### [*Recover*](recover.c)

Implement a program called `recover` that recovers JPEGs from a forensic image.

- Implement your program in a file called `recover.c` in a directory called `recover`.
- Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
- If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and `main` should return `1`.
- If the forensic image cannot be opened for reading, your program should inform the user as much, and `main` should return `1`.
- The files you generate should each be named `###.jpg`, where `###` is a three-digit decimal number, starting with `000` for the first image and counting up.
- Your program, if it uses `malloc`, must not leak any memory.

Your program should behave per the examples below.

```
$ ./recover
Usage: ./recover IMAGE
```
where `IMAGE` is the name of the forensic image. For example:

```
$ ./recover card.raw
```

---
### [*Reverse*](reverse/reverse.c)

Let’s write a program called called `reverse` that enables us to reverse a WAV file given by the user and create a new WAV file that contains the resulting reversed audio. For simplicity’s sake, we’ll limit the files we deal with to the WAV format. At the time the user executes the program, they should provide, using two command-line arguments, the name of the input file to be read and reversed, and the name of the output file they would like to save the resulting audio in. A successfully executed program should not output any text, and should create a WAV file with the user-specified name that plays the audio of the input WAV file in reverse. For example:

```
$ ./reverse input.wav output.wav
```

In `reverse.c`, you’ll notice that a few helpful libraries have been included, as well as a header file, `wav.h`. You’ll likely find these to be useful when implementing your program. We’ve left eight `TODO`s and two helper functions for you to fill in, and we recommend you tackle them in order from 1 to 8.

- In the first `TODO`, you should ensure the program accepts two command-line arguments: the name of the input WAV file and the name of the output WAV file. If the program does not meet these conditions, you should print an appropriate error message and return `1`, ending the program.
- In the second `TODO`, you should open your input file. We’ll need to open the input file in “read-only” mode, since we’ll only read data from the input file. It may be wise to check that the file has been opened successfully. Otherwise, you should print an appropriate error message and return `1`, exiting the program. We should hold off on opening the output file, though, lest we create a new WAV file before knowing the input file is valid!
- In the third `TODO`, you should read the header from the input file. Recall that, in `wav.h`, we’ve already implemented a struct that can store a WAV file’s header. Since we’ve written `#include "wav.h"` at the top of `reverse.c`, you, too, can use the `WAVHEADER` struct.
- In the fourth `TODO`, you should complete the `check_format` function. `check_format` takes a single argument, a `WAVHEADER` called `header`, representing a struct containing the input file’s header. If `header` indicates the file is indeed a WAV file, the `check_format` function should return `true`. If not, `check_format` should return `false`. To check if a file is of the WAV format, we can compare the elements from the input file header to those we would expect from a WAV file. It suffices to show the “WAVE” marker characters are found in the `format` member of the `WAVHEADER` struct.
- In the fifth `TODO`, you can now safely open the output file for writing. It would still be wise to check that the file has been opened successfully.
- The sixth `TODO` tells us to write the header to the output file. The reversed WAV file will still have the same underlying file structure as the input file (same size, number of channels, bits per sample, etc.), so it suffices to copy the header we read in from the input file in the third `TODO` to the output file.
- In the seventh `TODO`, you should implement the `get_block_size` function. `get_block_size`, like `check_format`, takes a single argument: this is a `WAVHEADER` called `header`, representing the struct containing the input file’s header. `get_block_size` should return an integer representing the **block size** of the given WAV file, in bytes. We can think of a block as a unit of auditory data. For audio, we calculate the size of each block with the following calculation: **number of channels** multiplied by **bytes per sample**. Luckily, the header contains all the information we need to compute these values. See too `wav.h`, to determine which members of `WAVHEADER` might be useful.
- The eighth and final `TODO` is where the actual reversing of the audio takes place. To do this, we need to read in each block of auditory data starting from the very end of the input file and moving backwards, simultaneously writing each block to the output file so they are written in reverse order. First, we should declare an array to store each block we read in. Then, it’s up to you to iterate through the input file audio data. You’ll want to be sure you read through all of the audio, but don’t erroneously copy any of the data from the header! Additionally, for testing purposes, we would like to maintain the order of the channels for each audio block. For example, in a WAV file with two channels (stereophonic sound), we want to make sure that the first channel of the last audio block in the input becomes the first channel of the first audio block in the output.
- Finally, be sure to close any files you’ve opened!

Here are a few examples of how the program should work. For example, if the user omits one of the command-line arguments:

```
$ ./reverse input.wav
Usage: ./reverse input.wav output.wav
```
Or if the user omits both of the command-line arugments:

```
$ ./reverse
Usage: ./reverse input.wav output.wav
```
Here’s how the program should work if the user provides an input file that is not an actual WAV file:

```
$ ./reverse image.jpg output.wav
Input is not a WAV file.
```
You may assume the user enters a valid output filename, such as `output.wav`.

A successfully executed program should not output any text, and should create a WAV file with the user-specified name that plays the audio of the input WAV file in reverse. For example:

```
$ ./reverse input.wav output.wav
```


## Practice Problems

---
### [*Bottom Up*](bottomup/bottomup.c)

Learning Goals
- Practice working with images
- Learn about metadata
- Learn more about how `struct`s can be useful

Go ahead and pull up the URLs to which `BITMAPFILEHEADER`and `BITMAPINFOHEADER`are attributed, per the comments in `bmp.h</code>. Take a close look at the members of the `BITMAPINFOHEADER``struct</code>. Use that information to write a bit of code in `bottomup.c`to change the image from bottom-up to top-down. The code in question needn’t be very complicated, particularly if you know what you’re doing!

Your program should behave per the examples below.

```
bottomup/ $ ./bottomup harvard_bottomup.bmp harvard_topdown.bmp
```
When your program is working correctly, you should see a new file, `harvard_topdown.bmp` in your `bottomup` directory. Open it up and see if the orientation of the image is correct.

---
### [*License*](license/license.c)

Learning Goals
- Practice working with files and file pointers
- More work with strings and arrays
- Debugging with `debug50`
- Use `valgrind` to check for memory leaks

If you open the `plates.txt` file, you’ll notice that there are actually 8 different license plate numbers. There are a few errors in the distribution code that are causing this to happen. Let’s start by walking through the code.

We first check for command-line arguments, since `argv[1]` should be the text file that contains the license plates. We then create a character array of length 7, since the plate numbers are 6 `char`s long and we need to save space for the NUL terminator. Now we create an array of `char *`’s (character pointers, otherwise known as `string`s!) to store the 8 plate numbers. We create a file pointer to our external text file, create a variable to hold the index of each array element, and begin reading the file and saving the plate numbers to the array. Finally, to test that we did this correctly, we print out the values in the array.

However, when we compile and execute this code, something is clearly wrong. You’ll need to make the appropriate corrections!

Your program should behave per the examples below.

```
license/ $ ./license plates.txt
11ZT00
1KAD21
78ZZ01
99ZZ11
72ZZ21
98ZZ31
44ZW41
34ZZ51
```