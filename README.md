# AI System

## Movie Recommendation System

AI System is a simple movie recommendation system made in C++. It recommends movies based on the genres that the user likes.

The system compares the user's preferences with the genres of available movies. Movies with more matching genres get a higher score and are shown first.

This project was created as part of an Artificial Intelligence project to understand the basic idea of recommendation systems and similarity matching.

---

## How It Works

The system follows a simple process:

```text
User Preferences
       ↓
Compare Movie Genres
       ↓
Calculate Matching Score
       ↓
Sort Movies
       ↓
Show Recommendations
```

For example, if the user enters:

```text
Action Sci-Fi Adventure
```

and a movie has:

```text
Action, Adventure, Sci-Fi
```

the movie gets a score of **3** because all three genres match.

---

## Technologies Used

* C++
* C++17
* VS Code
* CMake
* MinGW / g++

---

## Project Structure

```text
AI System
│
├── data
│   └── movies.txt
│
├── include
│   └── RecommendationSystem.h
│
├── src
│   ├── main.cpp
│   └── RecommendationSystem.cpp
│
├── build
├── README.md
└── CMakeLists.txt
```

### Main Files

**`movies.txt`**
Contains the movie names and their genres.

**`RecommendationSystem.h`**
Contains the `Movie` structure and `RecommendationSystem` class.

**`RecommendationSystem.cpp`**
Contains the logic for loading movies, matching genres, calculating scores, and sorting recommendations.

**`main.cpp`**
Takes the user's preferences and displays the recommendations.

**`CMakeLists.txt`**
Contains the configuration for building the project using CMake.

---

## Recommendation Logic

The system uses a simple genre-matching method.

For every movie, it compares the user's preferences with the movie's genres.

If a genre matches:

```text
score = score + 1
```

For example:

```text
User Preferences:
Action
Sci-Fi
Adventure

Movie:
Iron Man
Action
Adventure
Sci-Fi

Score = 3
```

The movies are then sorted according to their scores, with the highest-scoring movies appearing first.

---

## Example Output

```text
=====================================
       RECOMMENDED MOVIES
=====================================

1. Avengers Endgame | Similarity Score: 3
2. Iron Man | Similarity Score: 3
3. Avatar | Similarity Score: 3
4. Inception | Similarity Score: 2
5. The Martian | Similarity Score: 2
```

The recommendations change depending on the genres entered by the user.

---

## How to Run

Compile the project using:

```bash
g++ -Iinclude src/main.cpp src/RecommendationSystem.cpp -o ai-system
```

Then run:

```powershell
.\ai-system
```

You can also build the project using CMake:

```bash
cmake -S . -B build
cmake --build build
```

---

## Future Improvements

In the future, the project can be improved by adding:

* Movie ratings
* A larger movie dataset
* Weighted user preferences
* A graphical interface
* More advanced similarity methods
* Machine learning-based recommendations

---

## What I Learned

Through this project, I learned how to work with C++ classes, vectors, strings, file handling, sorting, and basic recommendation logic.

The project also helped me understand how user preferences can be compared with item information to generate simple recommendations.

---

## Project Status

**Status:** Completed Basic Version
**Language:** C++
**Project:** Artificial Intelligence — Project 3
