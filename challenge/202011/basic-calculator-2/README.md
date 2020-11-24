# memo

- BNFベースで解く
- 括弧がないので以下のようにすればよい. それぞれを関数として実装する
  - `expr = term [*/] term`
  - `term = number [+-] number`
  - `number = [1-9][0-9]*`
- 空白はすべて無視
