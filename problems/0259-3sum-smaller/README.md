# 回答メモ

- 3sum系の問題と同じ
- sortして 2点を動かすパターン
- i + low + high < targetが満たされるとき i と lowを固定すれば low < x <= highを満たす xはすべて条件を満たすのでまとめて個数を数え上げることができる
