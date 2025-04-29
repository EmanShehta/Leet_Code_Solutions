SELECT 
    s.user_id, 
    COALESCE(
        ROUND(
            COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) / NULLIF(COUNT(c.action), 0),
            2
        ), 
        0
    ) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c ON c.user_id = s.user_id
GROUP BY s.user_id;
