SELECT
  tmp.class
FROM
  (
    SELECT
      DISTINCT student,
      class
    FROM
      courses
  ) as tmp
GROUP BY
  tmp.class
HAVING
  COUNT(*) >= 5
;
