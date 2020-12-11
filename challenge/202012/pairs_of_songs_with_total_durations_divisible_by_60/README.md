# memo

- O(n^2)の回答だが, 重複する値をまとめて数え上げるようにし, ループ回数を減らす
- 例えば `[30, 10, 30, 60, 90]` のような場合 index 0の 30について探索する際, index 2に同値の 30が見つかるので以降和が 60で割り切れる組み合わせがあるなら, 個数をまとめて数え上げることができる