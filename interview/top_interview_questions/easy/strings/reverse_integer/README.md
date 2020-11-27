# memo

## compilerの undefined sanitizerの挙動

- undefinedな挙動を引き起こすことを一度でもやってしまうとエラーとなる
- 今回の場合, overflowがそもそも起きないようにする必要がある
  - 10倍した値を 10で割ったとき元の数になるかというのでは不十分
    - 10倍したとき, overflowしている可能性がある. signedの overflowは undefined behavior
    - そのため現在の値が最大値(INT_MAX)を 10で割った数よりも大きいというような調べ方をする必要がある
