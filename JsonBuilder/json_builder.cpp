#include "json_builder.h"

namespace json
{
    Builder& Builder::Value( json::Node&& value )
    {
        if ( main_node_.IsNull() )
        {
            main_node_ = std::move( value );
        }
        return *this;
    }

    Builder& Builder::StartDict()
    {
        return *this;
    }

    Builder& Builder::Key(const std::string& key )
    {
        return *this;
    }

    Builder& Builder::EndDict()
    {
        return *this;
    }

    Builder& Builder::StartArray()
    {
        return *this;
    }

    Builder& Builder::EndArray()
    {
        return *this;
    }

    json::Node Builder::Build()
    {
        return main_node_;
    }
}
