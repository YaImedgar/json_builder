#pragma once

#include "json.h"

namespace json
{
    class Builder
    {
    public:
        Builder() = default;

        Builder( const Builder& ) = delete;
        Builder( Builder&& ) = default;

        Builder& operator=( const Builder& ) = delete;
        Builder& operator=( Builder&& other ) = default;

        ~Builder() = default;

        Builder& Value( json::Node&& value );

        Builder& StartDict();
        Builder& Key( const std::string& key );
        Builder& EndDict();

        Builder& StartArray();
        Builder& EndArray();

        json::Node Build();

    private:
        json::Node main_node_;
    };
}

