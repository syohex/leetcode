SELECT
  id,
  MAX(CASE WHEN month = 'Jan' THEN revenue END) as Jan_Revenue,
  MAX(CASE WHEN month = 'Feb' THEN revenue END) as Feb_Revenue,
  MAX(CASE WHEN month = 'Mar' THEN revenue END) as Mar_Revenue,
  MAX(CASE WHEN month = 'Apr' THEN revenue END) as Apr_Revenue,
  MAX(CASE WHEN month = 'May' THEN revenue END) as May_Revenue,
  MAX(CASE WHEN month = 'Jun' THEN revenue END) as Jun_Revenue,
  MAX(CASE WHEN month = 'Jul' THEN revenue END) as Jul_Revenue,
  MAX(CASE WHEN month = 'Aug' THEN revenue END) as Aug_Revenue,
  MAX(CASE WHEN month = 'Sep' THEN revenue END) as Sep_Revenue,
  MAX(CASE WHEN month = 'Oct' THEN revenue END) as Oct_Revenue,
  MAX(CASE WHEN month = 'Nov' THEN revenue END) as Nov_Revenue,
  MAX(CASE WHEN month = 'Dec' THEN revenue END) as Dec_Revenue
FROM
  Department
GROUP BY
  id
;
