# memo

- vector ret, carry 初期値 1を用意
- digitsを逆(下の位)からループ
- 位の値 + carryをする
  - 10以上の場合 10で割った余りを retに `push_back` carry = 1とする
  - 10を超えない場合 carry = 0とする
- ループ後 carry == 1 の場合, retに 1を `push_back`
- retを逆順にして返す