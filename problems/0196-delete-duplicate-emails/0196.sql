DELETE
FROM
  Person
WHERE
  Id not in (
  SELECT
    tmp.min_id
  FROM(
    SELECT
      MIN(Id) as min_id
    FROM
      Person
    GROUP BY
      Email
  ) as tmp)
;
