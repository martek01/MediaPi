AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = mediapi
mediapi_SOURCES = main.cpp configuration.cpp database.cpp upnp/multicastsender.cpp upnp/rootdevice.cpp

AM_CPPFLAGS = $(BOOST_CPPFLAGS)
AM_LDFLAGS = $(BOOST_LDFLAGS)

mediapi_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_PROGRAM_OPTIONS_LIB)
