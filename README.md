# calculator-parser

# interpret & compiler

<h2>Gramer</h2>
<ul>
    <li>expr  := digit | `(` expr oprt expr </li>
    <li>oprt  := `*` | `/` | `+` | `-`</li>
    <li>digit := `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7`| `8` | `9`</li>
<ul>

<h2>IR</h2>
<ul>
    <li>PUSH n</li>
    <li>PLUS   replace 2 last element of stack with result of sum</li>
    <li>MIN   replace 2 last element of stack with result of mines</li>
    <li>MULT  replace 2 last element of stack with result of multipy</li>
    <li>DIV   replace 2 last element of stack with result of division</li>
    <li>PRINT print of last element on stack</li>
<ul>
