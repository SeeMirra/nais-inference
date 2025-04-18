#ifndef LLAMA_RUNNER_HPP
#define LLAMA_RUNNER_HPP

#include <common.h>
#include <functional>
#include <string>

class LlamaRunner {
    private:
        bool should_stop_generation;
        bool is_waiting_input;
        bool should_output_prompt;
        std::string input;
        std::function<void(std::string)> glog;

    public:
        LlamaRunner(
            bool should_output_prompt = true,
            std::function<void(std::string)> glog = [](auto s){}
        );
        ~LlamaRunner();
        static bool file_exists(const std::string &path);
        static bool file_is_empty(const std::string &path);
        static void llama_log_callback_logTee(ggml_log_level level, const char * text, void * user_data);
        std::string llama_generate_text(
            std::string prompt,
            llama_context_params  params,
            std::function<void(std::string)> on_generate_text_updated,
            std::function<void()> on_input_wait_started,
            std::function<void(std::string)> on_generate_text_finished
        );
        void llama_stop_generate_text();
        void set_input(std::string input);
        bool get_is_waiting_input();
};

#endif //LLAMA_RUNNER_H
