# Defines
#  OGG_FOUND
#  OGG_INCLUDE_DIR
#  OGG_LIBRARY
#  VORBIS_LIBRARY
#  VORBIS_FILE_LIBRARY
#

# check for cache to avoid littering log
IF(OGG_INCLUDE_DIR AND OGG_LIBRARY AND VORBIS_LIBRARY)
	SET(OGG_BE_QUIET TRUE)
ENDIF(OGG_INCLUDE_DIR AND OGG_LIBRARY AND VORBIS_LIBRARY)


FIND_PATH(OGG_INCLUDE_DIR ogg/ogg.h)
FIND_LIBRARY(OGG_LIBRARY NAMES ogg)
FIND_LIBRARY(VORBIS_LIBRARY NAMES vorbis)

#on macosx the vorbisfile library is part of the vorbisone... 
#IF(NOT APPLE)
# comment above is full of lies
	FIND_LIBRARY(VORBIS_FILE_LIBRARY NAMES vorbisfile)
#ENDIF(NOT APPLE)

IF(OGG_INCLUDE_DIR AND OGG_LIBRARY AND VORBIS_LIBRARY AND (APPLE OR VORBIS_FILE_LIBRARY))
	SET(OGG_FOUND TRUE)
	IF(NOT OGG_BE_QUIET)
		MESSAGE(STATUS "OGG/Vorbis includes: ${OGG_INCLUDE_DIR}")
		MESSAGE(STATUS "OGG library        : ${OGG_LIBRARY}")
		MESSAGE(STATUS "Vorbis library     : ${VORBIS_LIBRARY}")
		MESSAGE(STATUS "Vorbis file library: ${VORBIS_FILE_LIBRARY}")
	ENDIF(NOT OGG_BE_QUIET)
ELSE(OGG_INCLUDE_DIR AND OGG_LIBRARY AND VORBIS_LIBRARY AND (APPLE OR VORBIS_FILE_LIBRARY))
	SET(OGG_FOUND FALSE)
	MESSAGE("OGG/Vorbis was not found on this system!")
ENDIF(OGG_INCLUDE_DIR AND OGG_LIBRARY AND VORBIS_LIBRARY AND (APPLE OR VORBIS_FILE_LIBRARY))

MARK_AS_ADVANCED(
	OGG_INCLUDE_DIR
	OGG_LIBRARY
	VORBIS_LIBRARY
	VORBIS_FILE_LIBRARY
)
