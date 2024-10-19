cmake_minimum_required(VERSION 3.2.0)
set(CMAKE_CXX_STANDARD 17)

project(force_me_to_learn)

set(force_me_to_learn_header
	Result.h
	Translation.h
	CSVUtils.h
	DataLoader.h
)

set(force_me_to_learn_sources
	main.cpp
	CSVUtils.cpp
	DataLoader.cpp
)

add_executable(force_me_to_learn
	# sources
	${force_me_to_learn_sources}

	# headers
	${force_me_to_learn_header}
)
