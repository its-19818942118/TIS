# Blessed Format

## The Blessed Format or the Block Formatting rule

### Function Declarations

```cpp
int
    main
    ( void )
;
```

### Function Definitions

```cpp
int
    main
    ( void )
{
    /* optional new line */
    // CODE HERE MUST
    /* optional new line */
}
```

eg:

```cpp
int
    main
    ( void )
{
    
    int
        x
        { 9 } /* bracket initialization */
    ; // valid
    
}
```

### Using Template Types

Must

```cpp
std::optional <std::vector <std::string>>; // invalid
std::optional <std::vector <std::string> >; // invalid

using
    vecStr_t =
    std::vector <std::string>
;

std::optional <vecStr_t>
    someType
; // valid
```
