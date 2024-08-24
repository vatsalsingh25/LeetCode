# Write your MySQL query statement below
-- STEP 1
-- SELECT *
-- FROM Students 
-- CROSS JOIN Subjects
-- ORDER BY student_id, subject_name 

SELECT a.student_id, a.student_name, b.subject_name, COUNT(e.student_id) as attended_exams
FROM Students as a 
CROSS JOIN Subjects as b
LEFT JOIN Examinations as e
USING(student_id, subject_name)
GROUP BY student_id, subject_name
ORDER BY student_id, subject_name ;