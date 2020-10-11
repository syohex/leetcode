SELECT
  e1.Name as Employee
FROM
  Employee as e1
INNER JOIN
  Employee as e2
ON
  e1.ManagerId = e2.Id
WHERE
  e1.Salary > e2.Salary
;
