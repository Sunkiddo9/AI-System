#include <iostream>
#include <vector>
#include <string>

#include "RecommendationSystem.h"

int main() {

    RecommendationSystem system;

    system.loadMovies("data/movies.txt");

    std::cout << "=====================================\n";
    std::cout << "          AI SYSTEM\n";
    std::cout << "     Movie Recommendation System\n";
    std::cout << "=====================================\n\n";

    std::cout << "Choose your favorite genres.\n";
    std::cout << "Enter genres separated by spaces.\n\n";

    std::cout << "Available genres:\n";
    std::cout << "Action\n";
    std::cout << "Adventure\n";
    std::cout << "Sci-Fi\n";
    std::cout << "Drama\n";
    std::cout << "Thriller\n";
    std::cout << "Crime\n";
    std::cout << "Romance\n";
    std::cout << "Comedy\n\n";

    std::cout << "Enter your preferences: ";

    std::vector<std::string> preferences;

    std::string preference;

    while (std::cin >> preference) {
        preferences.push_back(preference);

        if (std::cin.peek() == '\n') {
            break;
        }
    }

    std::vector<Movie> recommendations =
        system.getRecommendations(preferences);

    std::cout << "\n=====================================\n";
    std::cout << "       RECOMMENDED MOVIES\n";
    std::cout << "=====================================\n\n";

    int count = 0;

    for (const auto& movie : recommendations) {

        if (movie.score == 0) {
            continue;
        }

        std::cout << ++count << ". "
                  << movie.name
                  << " | Similarity Score: "
                  << movie.score
                  << "\n";

        if (count == 5) {
            break;
        }
    }

    if (count == 0) {
        std::cout << "No matching movies found.\n";
    }

    std::cout << "\nThank you for using AI System!\n";

    return 0;
}