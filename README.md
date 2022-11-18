Build command: 
    g++ -fdiagnostics-color=always -g main.cpp -o main.exe

Find database under : 
    path/to/Satisfactory/CommunityResources/Docs

Bugs encountered :
    - By default, game DB JSON file is UTF16 encoded. Parsing it only works with UTF8 encoding.
        Issue (resolved) https://github.com/nlohmann/json/issues/3838
        UTF8 conversion can be done with NotePad++ ("Encoding" menu)
