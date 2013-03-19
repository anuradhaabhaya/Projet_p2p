drop table connected_users;
drop table files;
drop table registered_users;

-- Tables creation

CREATE TABLE registered_users (
	user_id SERIAL PRIMARY KEY, 
	login VARCHAR(80), 
	password VARCHAR(80)
);

-- Once connected, users are given session_id
CREATE TABLE connected_users (
	session_id SERIAL PRIMARY KEY, 
	user_id SERIAL,
	address VARCHAR(20), 
	port VARCHAR(10)
);

-- 
CREATE TABLE files (
	file_id SERIAL PRIMARY KEY, 
	name VARCHAR(100), 
	description VARCHAR(255), 
	owner_id SERIAL
); 

-- id will be automatically updated
-- insert into registered_users (login, password) VALUES ('jk', md5('jkjk'));

-- FK constraints 
ALTER TABLE connected_users 
ADD CONSTRAINT connected_users_fk1  
FOREIGN KEY (user_id) REFERENCES registered_users(user_id); 

ALTER TABLE files 
ADD CONSTRAINT files_fk1  
FOREIGN KEY (owner_id) REFERENCES registered_users(user_id); 


SELECT * FROM connected_users;
SELECT * FROM registered_users;
SELECT * FROM files;

