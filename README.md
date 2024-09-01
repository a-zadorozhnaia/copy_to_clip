# CopyToClipboard
Program for copying text or a file transferred as parameters during startup to the clipboard.

## Details
What supports:
- Copy text
- Copy file (if it exists, otherwise copy the path as text)

## Compatibility
- Linux

## How to build
### Install xclip
```
sudo apt install xclip
```
### Build project
In the project directory, create a build and go to it:
```
mkdir build
cd build
```
Run cmake:
```
cmake ..
```
Run make:
```
make
```
## How to use
When running in terminal, pass one argument in single quotes:
```
./copy_to_clip 'Some text'
```
or
```
./copy_to_clip '/path_to_file/filename'
```
Now you can paste the copied file or text into a text editor or file manager by 'ctrl + v'.

## Tested with
- Ubuntu 22.04
- Copy .txt, .png, .bmp, without extension, with unknown extension, hidden files
- Copy multiline text
- Copy files with relativa, absolute and "tilda" path

## Stack
- Cmake 3.22.1
- xclip
