#!/bin/bash

echo main headers
for file in *.h;
do
	clang-format -i -style=file $file
done

echo main cppfiles
for file in *.cpp;
do
	clang-format -i -style=file $file
done

echo roadfighter/rf/headers
for file in roadfighter/rf/*.h;
do
	clang-format -i -style=file $file
done

echo roadfighter/src/cppfiles
for file in roadfighter/src/*.cpp;
do
	clang-format -i -style=file $file
done

echo roadfighterSFML/include/headers
for file in roadfighterSFML/include/*.h;
do
	clang-format -i -style=file $file
done

echo roadfighterSFML/src/cppfiles
for file in roadfighterSFML/src/*.cpp;
do
	clang-format -i -style=file $file
done
