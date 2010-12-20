
.PHONY: all pkg clean

FTINCLUDE	:= $(PS3DEV)/ppu/include/freetype/freetype.h

all:
	
	$(MAKE) -C spheres3D
	$(MAKE) -C sprites2D
	$(MAKE) -C fonts
	$(MAKE) -C surfaces
	@if test -e $(FTINCLUDE); then $(MAKE) -C fonts_from_ttf; fi

pkg:
	$(MAKE) pkg -C spheres3D
	$(MAKE) pkg -C sprites2D
	$(MAKE) pkg -C fonts
	$(MAKE) pkg -C surfaces
	@if test -e $(FTINCLUDE); then $(MAKE) pkg -C fonts_from_ttf; fi

clean:
	$(MAKE) clean -C spheres3D
	$(MAKE) clean -C sprites2D
	$(MAKE) clean -C fonts
	$(MAKE) clean -C surfaces
	@if test -e $(FTINCLUDE); then $(MAKE) clean -C fonts_from_ttf; fi


