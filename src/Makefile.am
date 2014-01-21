AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = mediapi
mediapi_SOURCES = main.cpp mediaserver.cpp database.cpp  

AM_CPPFLAGS = $(BOOST_CPPFLAGS) -I$(top_srcdir)/lib/platinum/include -I$(top_srcdir)/lib/neptune/include
AM_LDFLAGS = $(BOOST_LDFLAGS) -L$(top_srcdir)/lib/platinum/lib -L$(top_srcdir)/lib/neptune/lib -framework foundation 

mediapi_LDADD = $(BOOST_FILESYSTEM_LIB) $(BOOST_SYSTEM_LIB) $(BOOST_PROGRAM_OPTIONS_LIB) -lplatinum -lneptune -laxtls -lpltmediaserver 
