CREATE TABLE purchases (
    user_id INTEGER NOT NULL,
    date DATETIME NOT NULL,
    symbol TEXT NOT NULL,
    quantity INTEGER NOT NULL,
    price REAL,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
CREATE INDEX user_id ON purchases(user_id);