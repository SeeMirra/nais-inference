#pragma once

#include "llama.h" // Include the original llama.h

struct CustomLlamaContextParams {
    llama_context_params base_params; // Embed the original struct

    // Add your custom fields here
    std::string model;
    bool interactive;
    std::string input_prefix;
    std::string input_suffix;
    bool special;
    int n_predict;
    int n_keep;

    struct SamplingParams {
        float temp;
        float penalty_repeat;
        int penalty_last_n;
        bool penalize_nl;
        int top_k;
        float top_p;
        float min_p;
        std::string grammar;
    } sparams;

    // Constructor to initialize with default values
    CustomLlamaContextParams() : 
        base_params(llama_context_default_params()), // Initialize the base struct
        model(""),
        interactive(false),
        input_prefix(""),
        input_suffix(""),
        special(false),
        n_predict(0),
        n_keep(0),
        sparams{1.0f, 1.0f, 0, false, 40, 0.9f, 0.0f, ""}
    {}
};