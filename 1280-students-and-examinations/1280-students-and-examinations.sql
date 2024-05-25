# Write your MySQL query statement below
select s.student_id ,s.student_name,sub.subject_name,count(exam.subject_name) as attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations exam ON s.student_id = exam.student_id AND sub.subject_name = exam.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;
