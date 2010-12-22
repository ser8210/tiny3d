Tiny3D
======

Tiny3D is one library to work with 2D/3D graphics.

It uses PSL1GHT and install the libraries in PSL1GHT/lib, C Header files
in PSL1GHT/include

see the 'docs' folder to know more

Credits
-------

    Hermes         - Author
    ElSemi         - Vertex Program Compiler and other useful sample code
    HACKERCHANNEL  - PSL1GHT
    Oopo           - ps3libraries

License
-------
    
    It use the same PSL1GHT license (it have one? XD)
    
    Some samples can use LPGL, GPL, OFL or maybe others licenses depending of the libraries 
    or datas used. 

Environment
-----------

    libtiny3d.a -> the library
    
    tiny3d.h    -> 2D/3D functions

    matrix.h    -> Math support for matrix

    --------------------------------------

    libfont.a   -> library to work with fixed fonts (now allow capture from True Type Fonts)
    libfont.h   


Building
--------

You need the environment variable $PSL1GHT defined

    cd tiny3d
    make
    
It makes and install libs and samples.

Remember you can descend later to the samples folder to compile ONLY the samples:

    cd samples
    make
    make pkg

Current Status
--------------

Added libfont.a with support for fonts based in bitmaps arrays of characters

It works with six samples: spheres3D, sprites2D, surfaces, fonts, fonts_from_ttf
and now ps3loadx

NOTE: fonts_from_ttf requires Oopo ps3libraries libz and freetype. ps3loadx requires libz and libzip.

You can download from here: http://mods.elotrolado.net/~hermes/ps3/ps3dev/ppu_oopo-ps3libraries.rar

