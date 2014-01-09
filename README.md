MediaPi
=======

UPnP media server intended for the Raspberry Pi based on the Platinum UPnP SDK

Features
--------
- Recursively scan directories for media content
- Get content information from IMDB
- Edit content presentation (e.g. directory-name, -structure)

Feature wish list
-----------------
- Automatically detect new content
- Get content information from metadata (e.g. ID3-Tags)
- Web-frontend
- Highly customisable through config file(s)
- Editable database

Libraries
---------
- Platinum UPnP: Provides UPnP server structure
- Neptune: Runtime class library used by Platinum UPnP
- SQLite: Handles database
- Boost: Parses config file(s) and makes HTTP requests for IMDB
