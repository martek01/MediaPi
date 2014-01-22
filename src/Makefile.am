AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = mediapi
mediapi_SOURCES = main.cpp configuration.cpp database.cpp configs.cpp

AM_CPPFLAGS = $(BOOST_CPPFLAGS) -I/usr/local/include/platinum -I/usr/local/include/neptune
AM_LDFLAGS = $(BOOST_LDFLAGS) -framework foundation 

mediapi_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_PROGRAM_OPTIONS_LIB) -lPlatinum -lNeptune -laxTLS -lPltMediaServer 
