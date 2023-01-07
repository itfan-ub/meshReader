if not exist build md build
cd build
cmake .. -G "Visual Studio 17 2022" -B .
msbuild meshReader.sln
msbuild /p:Configuration=Release test_executable.vcxproj