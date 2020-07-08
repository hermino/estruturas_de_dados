SELECT REGEXP_REPLACE(cpf, '(\d{3})(\d{3})(\d{3})(\d{2})', '\1.\2.\3-\4') 
AS cpf
FROM natural_person;
