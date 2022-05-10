#include "json_builder.h"

namespace json
{
    using std::string_literals::operator""s;

    Builder& Builder::Value( json::Node&& value )
    {
        if ( root_ == nullptr )
        {
            root_ = value;
            nodes_stack_.emplace_back( &root_ );
        }
        else
        {
        }
        return *this;
    }

    Builder& Builder::StartDict()
    {
        root_ = Dict{};
        return *this;
    }

    Builder& Builder::Key( const std::string& key )
    {
        std::get< json::Dict >( nodes_stack_.back()->GetValue() );
        Dict dict;
        root_ = &dict[key];
        key_ = key;
        return *this;
    }

    Builder& Builder::EndDict()
    {
        return *this;
    }

    Builder& Builder::StartArray()
    {
        root_ = Dict{};
        return *this;
    }

    Builder& Builder::EndArray()
    {
        return *this;
    }

    json::Node Builder::Build()
    {
        return root_;
    }
}
