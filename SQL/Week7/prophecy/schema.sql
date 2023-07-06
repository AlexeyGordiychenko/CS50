DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS houses;
DROP TABLE IF EXISTS assignments;

CREATE TABLE students (
    id INTEGER,
    student_name TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE assignments (
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id),
    PRIMARY KEY(student_id, house_id)
);
