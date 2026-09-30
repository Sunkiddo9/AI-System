#ifndef RECOMMENDATION_SYSTEM_H
#define RECOMMENDATION_SYSTEM_H

#include <string>
#include <vector>

struct Movie {
    std::string name;
    std::vector<std::string> genres;
    int score;
};

class RecommendationSystem {
private:
    std::vector<Movie> movies;

public:
    void loadMovies(const std::string& filename);

    std::vector<Movie> getRecommendations(
        const std::vector<std::string>& preferences
    );
};

#endif