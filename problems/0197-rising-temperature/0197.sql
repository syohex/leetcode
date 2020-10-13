SELECT
  w1.Id
FROM
  Weather w1, Weather w2
WHERE
-- SUBDATE(w1.recordDate, 1) = w2.recordDate MySQL
  JulianDay(w1.recordDate) - JulianDay(w2.recordDate) = 1 -- SQLite
  AND w1.Temperature > w2.Temperature
;
  
