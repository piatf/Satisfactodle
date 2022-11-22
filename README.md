Build command: 
    [in Project Directory]
    cmake --build ./build --config Debug --target Satisfactodle -j 6 --

If build/ is removed :
    VsCode => CMAKE extensions => Project outline => "More actions..." => Configure all projects

Find database under : 
    path/to/Satisfactory/CommunityResources/Docs

Bugs encountered :
    - By default, game DB JSON file is UTF16 encoded. Parsing it only works with UTF8 encoding.
        Issue (resolved) https://github.com/nlohmann/json/issues/3838
        UTF8 conversion can be done with NotePad++ ("Encoding" menu)
