# suffix_array
もし``s="abcde"``なら、suffix_arrayは``["abcde","bcde","cde","de","e"]``となり、これは辞書順で0番目、1番目、...、4番目であるから``[0,1,2,3,4]``が返ってくる。``edcba``なら逆で返ってくる。いわゆる配列の``i``番目は``s``のすべての``suffix``の辞書順で何番目かを表す。

# lcp_array
