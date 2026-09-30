#include "RecommendationSystem.h"

#include <algorithm>
#include <fstream>
#include <sstream>

void RecommendationSystem::loadMovies(const std::string& filename) {

    std::ifstream file(filename);

    if (!file.is_open()) {
        return;
    }

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string name;
        std::string genreData;

        std::getline(ss, name, '|');
        std::getline(ss, genreData);

        Movie movie;
        movie.name = name;
        movie.score = 0;

        std::stringstream genreStream(genreData);

        std::string genre;

        while (std::getline(genreStream, genre, ',')) {
            movie.genres.push_back(genre);
        }

        movies.push_back(movie);
    }

    file.close();
}


std::vector<Movie> RecommendationSystem::getRecommendations(
    const std::vector<std::string>& preferences) {

    std::vector<Movie> recommendations = movies;

    for (auto& movie : recommendations) {

        movie.score = 0;

        for (const auto& userPreference : preferences) {

            for (const auto& genre : movie.genres) {

                if (userPreference == genre) {
                    movie.score++;
                }
            }
        }
    }

    std::sort(
        recommendations.begin(),
        recommendations.end(),
        [](const Movie& a, const Movie& b) {
            return a.score > b.score;
        }
    );

    return recommendations;
}