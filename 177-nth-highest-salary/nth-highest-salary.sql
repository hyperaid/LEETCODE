CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare M INT;
    SET M=N-1;
 RETURN (
      # Write your MySQL query statement below.
       SELECT Distinct salary
        FROM Employee
        Order by salary desc
        limit 1
        offset M

  );
END
 