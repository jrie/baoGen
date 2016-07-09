# baoGen
A bao game field/playboard csv generator

baoGen is a bao game field/playboard generator.

Using the command line, muliple fields (up to 100) with variing field widths (power of 2) and a custom set of playstones can be generated.

## The command line switches

### Usage:

"baoGen2"
(uses default settings)

"baoGen2 p32 f16 b10"

or anything like:
  "baoGen2 p24"

The program tells you if something is wrong.

which translates to:

'p' : Amount of playstones (Default: 32 = 'p32')

'f' : Amount of fields per player, diviseable by 2 (Default: 16 = 'f16')

'b' : Amount of playboards to create (Default: 10 = 'b10')

Not all switches have to be used. All playboards are saved then to 'playboard.csv'.

##How it works
baoGen places randomly the set stones (by default 32) onto the fields (16 by default) of a player. By default 10 playboards are created this way. And during the process those playboards are written out to a file called 'playboard.csv'.

## Why?
This generator was written for the 3rd coding competition @ www.ngb.to
