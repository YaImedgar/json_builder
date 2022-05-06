# Introduction
This is a json C++ builder implementation. Which helps with the construction of a json document

## Example
```c++
 json::Builder{}
    .StartDict()
        .Key( "key1"s ).Value( 123 )
        .Key( "key2"s ).Value( "value2"s )
        .Key( "key3"s ).StartArray()
            .Value( 456 )
            .StartDict().EndDict()
            .StartDict()
                .Key( ""s )
                .Value( nullptr )
            .EndDict()
            .Value( ""s )
        .EndArray()
    .EndDict()
    .Build()
```

```json
{
    "key1": 123,
    "key2": "value2",
    "key3": [ 456, {}, { "" : null }, "" ]
}
```
