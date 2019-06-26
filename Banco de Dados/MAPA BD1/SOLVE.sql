create schema esoft_bd1;

use esoft_bd1;

create table cliente (
	id int not null primary key auto_increment,
    nome varchar(100) not null,
    endereco varchar(100),
    complemento varchar(20),
    bairro varchar(50),
    cidade varchar(50),
    estado char(2),
    tipo char(1),
    key(id));

insert into cliente (nome, endereco, complemento, bairro, cidade, estado, tipo) 
    values 
    ('Guionardo','R Manoel Barreto, 90', 'Ap 501', 'Victor Konder', 'Blumenau', 'SC', 'F'),
    ('Guiosoft', 'Microsoft Way, 1', '', 'Redmond','Redmond','WA','J');
    
create table item (
	id int not null primary key auto_increment,
    nome varchar(100),
    unitario numeric(12,2),
    tipo char(1),
    key(id));
    
insert into item (nome, unitario, tipo)
    values
    ('CPU Intel i3',    300,    'P'),
    ('Placa Mãe Asus',  200,    'P'),
    ('Cooler Intel',     30,    'P'),
    ('Manutenção',       50,    'S'),
    ('Suporte Remoto',   25,    'S');
    
create table pedido (
	id int not null primary key auto_increment,
    data date not null,
    id_cliente int not null,
    total numeric(12,2) default 0,
    constraint fk_cliente_pedido
		foreign key (id_cliente) references item (id)
        on delete cascade
        on update restrict);        
        
insert into pedido (data, id_cliente)
	values
	('2019-06-10',1),
    ('2019-06-09',2);
        
create table pedido_item (
	id int not null primary key auto_increment,
    id_pedido int not null,
    id_item int not null,
    quantidade numeric(12,3) default 0,
    unitario numeric(12,2) default 0,
    constraint fk_pedido
		foreign key (id_pedido) references pedido (id)
        on delete cascade
        on update restrict,
	constraint fk_item
		foreign key (id_item) references item (id)
        on delete cascade
        on update restrict);
        
CREATE TRIGGER pedido_item_ai 
    AFTER INSERT ON pedido_item
    FOR EACH ROW
    update pedido p set p.total = p.total + new.quantidade * new.unitario where id=new.id_pedido;

insert into pedido_item (id_pedido, id_item, quantidade, unitario)
	values 
    (1,	1,	3,	20),
    (1,	2,	1,	40),
    (2,	3,	1,	40),
    (2,	4,	4,	50);