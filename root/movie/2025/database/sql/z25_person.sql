-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 21:48
-- Server-Version: 10.4.32-MariaDB
-- PHP-Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `x25_athene`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `z25_person`
--

CREATE TABLE `z25_person` (
  `kcPerson` varchar(8) NOT NULL COMMENT 'BiWilder',
  `sName` varchar(80) NOT NULL COMMENT 'Billy Wilder',
  `bSex` tinyint(1) NOT NULL,
  `tBirthday` date NOT NULL COMMENT '22/06/1906',
  `sUrl` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_person`
--

INSERT INTO `z25_person` (`kcPerson`, `sName`, `bSex`, `tBirthday`, `sUrl`) VALUES
('AaLyne', 'Adrian Lyne', 0, '1941-03-04', '#https://de.wikipedia.org/wiki/Adrian_Lyne#'),
('AkKu', 'Akira Kurosawa', 0, '1910-03-23', '#https://de.wikipedia.org/wiki/Akira_Kurosawa#'),
('AlGoIna', 'Alejandro González Iñárritu', 0, '1963-08-15', '#https://de.wikipedia.org/wiki/Alejandro_Gonz%C3%A1lez_I%C3%B1%C3%A1rritu#'),
('AlHitckk', 'Alfred Hitchkock', 0, '1899-08-13', '#https://de.wikipedia.org/wiki/Alfred_Hitchcock#'),
('AlParker', 'Alan Parker', 0, '1944-02-14', '#https://de.wikipedia.org/wiki/Alan_Parker#'),
('AlSilvst', 'Alan Silvestri', 0, '1950-03-26', '#https://de.wikipedia.org/wiki/Alan_Silvestri#'),
('ArRa', 'A. R. Rahman', 0, '1966-01-06', '#https://de.wikipedia.org/wiki/A._R._Rahman#'),
('BaBeyzai', 'Bahram Beyzai', 0, '1938-12-26', '#https://en.wikipedia.org/wiki/Bahram_Beyzai#'),
('BaLevi', 'Barry Levinson', 0, '1942-04-06', '#https://de.wikipedia.org/wiki/Barry_Levinson#'),
('BeHerr', 'Bernard Herrmann', 0, '1911-06-29', '#https://de.wikipedia.org/wiki/Bernard_Herrmann#'),
('BiConti', 'Bill Conti', 0, '1942-04-13', '#https://de.wikipedia.org/wiki/Bill_Conti#'),
('BiWilder', 'Billy Wilder', 0, '1906-06-22', '#https://de.wikipedia.org/wiki/Billy_Wilder#'),
('BramSt', 'Bram Stoker', 0, '1847-11-08', '#https://de.wikipedia.org/wiki/Bram_Stoker#'),
('BrDePa', 'Brian De Palma', 0, '1940-09-11', '#https://de.wikipedia.org/wiki/Brian_De_Palma#'),
('ClintEwd', 'Clint Eastwood', 0, '1930-05-31', '#https://de.wikipedia.org/wiki/Clint_Eastwood#'),
('DaCrobg', 'David Cronenberg', 0, '1943-03-15', '#https://de.wikipedia.org/wiki/David_Cronenberg#'),
('DaFinch', 'David Fincher', 0, '1962-08-28', '#https://de.wikipedia.org/wiki/David_Fincher#'),
('DaLean', 'David Lean', 0, '1908-03-25', '#https://de.wikipedia.org/wiki/David_Lean#'),
('DaLynch', 'David Lynch', 0, '1946-01-20', '#https://de.wikipedia.org/wiki/David_Lynch#'),
('DaZucker', 'David Zucker', 0, '1947-10-16', '#https://de.wikipedia.org/wiki/David_Zucker#'),
('DoDörr', 'Doris Dörrie', 1, '1955-05-26', '#https://de.wikipedia.org/wiki/Doris_D%C3%B6rrie#'),
('EdAllPoe', 'Edgar Allan Poe', 0, '1809-01-19', 'https://de.wikipedia.org/wiki/Edgar_Allan_Poe#https://de.wikipedia.org/wiki/Edgar_Allan_Poe#'),
('EdWallce', 'Edgar Wallace', 0, '1875-04-01', '#https://de.wikipedia.org/wiki/Edgar_Wallace#'),
('Ekazan', 'Elia Kazan', 0, '1909-09-07', '#https://de.wikipedia.org/wiki/Elia_Kazan#'),
('EnMorri', 'Ennio Morricone', 0, '1928-11-10', '#https://de.wikipedia.org/wiki/Ennio_Morricone#'),
('EtJoCoen', 'Ethan und Joel Coen (Coen Brothers)', 0, '1954-11-29', '#https://de.wikipedia.org/wiki/Ethan_und_Joel_Coen#'),
('FaAkin', 'Fatih Akin', 0, '1973-08-25', '#https://de.wikipedia.org/wiki/Fatih_Akin#'),
('FrFoCopp', 'Francis Ford Coppola', 0, '1939-04-07', '#https://de.wikipedia.org/wiki/Francis_Ford_Coppola#'),
('FrLang', 'Fritz Lang', 0, '1890-12-05', '#https://de.wikipedia.org/wiki/Fritz_Lang#'),
('FrTruf', 'François Truffaut', 0, '1932-02-06', '#https://de.wikipedia.org/wiki/Fran%C3%A7ois_Truffaut#'),
('FrZinn', 'Fred Zinnemann', 0, '1907-04-29', '#https://de.wikipedia.org/wiki/Fred_Zinnemann#'),
('GeCukor', 'George Cukor', 0, '1899-07-07', '#https://de.wikipedia.org/wiki/George_Cukor#'),
('GeLucas', 'George Lucas', 0, '1944-05-14', '#https://de.wikipedia.org/wiki/George_Lucas#'),
('GeMiller', 'George Miller', 0, '1945-03-03', '#https://de.wikipedia.org/wiki/George_Miller_(Regisseur)#'),
('GeOrwell', 'George Orwell', 0, '1903-06-25', '#https://de.wikipedia.org/wiki/George_Orwell#'),
('GeRoddby', 'Gene Roddenberry', 0, '1921-08-19', '#https://de.wikipedia.org/wiki/Gene_Roddenberry#'),
('GeStevns', 'George Stevens', 0, '1904-12-18', '#https://de.wikipedia.org/wiki/George_Stevens#'),
('HeManci', 'Henry Mancini', 0, '1924-04-16', '#https://de.wikipedia.org/wiki/Henry_Mancini#'),
('HoShore', 'Howard Shore', 0, '1946-10-18', '#https://de.wikipedia.org/wiki/Howard_Shore#'),
('InBergm', 'Ingmar Bergman', 0, '1918-07-14', '#https://de.wikipedia.org/wiki/Ingmar_Bergman#'),
('JaBrooks', 'James L. Brooks', 0, '1940-05-09', '#https://de.wikipedia.org/wiki/James_L._Brooks#'),
('JaCamern', 'James Cameron', 0, '1954-08-16', '#https://de.wikipedia.org/wiki/James_Cameron#'),
('JeGoldsm', 'Jerry Goldsmith', 0, '1929-02-10', '#https://de.wikipedia.org/wiki/Jerry_Goldsmith#'),
('JeJaAn', 'Jean-Jacques Annaud', 0, '1943-10-01', '#https://de.wikipedia.org/wiki/Jean-Jacques_Annaud#'),
('JeZucker', 'Jerry Zucker', 0, '1950-03-11', '#https://de.wikipedia.org/wiki/Jerry_Zucker#'),
('JiAbra', 'Jim Abrahams', 0, '1944-05-10', '#https://de.wikipedia.org/wiki/Jim_Abrahams#'),
('JoBarry', 'John Barry', 0, '1933-11-03', '#https://de.wikipedia.org/wiki/John_Barry_(Filmkomponist)#'),
('JoCarpen', 'John Carpenter', 0, '1948-01-14', '#https://de.wikipedia.org/wiki/John_Carpenter#'),
('JoFord', 'John Ford', 0, '1894-02-01', '#https://de.wikipedia.org/wiki/John_Ford#'),
('JoHuston', 'John Huston', 0, '1906-08-05', '#https://de.wikipedia.org/wiki/John_Huston#'),
('JoSch', 'John Schlesinger', 0, '1926-02-16', '#https://de.wikipedia.org/wiki/John_Schlesinger#'),
('JoWillia', 'John Williams', 0, '1932-02-08', 'https://de.wikipedia.org/wiki/John_Williams_(Komponist)#https://de.wikipedia.org/wiki/John_Williams_(Komponist)#'),
('JRRTol', 'J. R. R. Tolkien', 0, '1892-09-02', '#https://de.wikipedia.org/wiki/J._R._R._Tolkien#'),
('JuVerne', 'Jules Verne', 0, '1828-02-08', 'https://de.wikipedia.org/wiki/Jules_Verne#https://de.wikipedia.org/wiki/Jules_Verne#'),
('KaBigelw', 'Kathryn Bigelow', 1, '1951-11-27', '#https://de.wikipedia.org/wiki/Kathryn_Bigelow#'),
('LuBunel', 'Luis Buñuel', 0, '1900-02-22', '#https://en.wikipedia.org/wiki/Luis_Bu%C3%B1uel#'),
('MaHarron', 'Mary Harron', 0, '1953-01-12', '#https://de.wikipedia.org/wiki/Mary_Harron#'),
('MaScorse', 'Martin Scorsese', 0, '1942-11-17', '#https://de.wikipedia.org/wiki/Martin_Scorsese#'),
('MeBrooks', 'Mel Brooks', 0, '1926-02-28', '#https://de.wikipedia.org/wiki/Mel_Brooks#'),
('MiCurtiz', 'Michael Curtiz', 0, '1886-12-24', '#https://de.wikipedia.org/wiki/Michael_Curtiz#'),
('MiForman', 'Miloš Forman', 0, '1932-02-18', '#https://de.wikipedia.org/wiki/Milo%C5%A1_Forman#'),
('MiMoore', 'Michael Moore', 0, '1954-04-23', '#https://de.wikipedia.org/wiki/Michael_Moore#'),
('MiNich', 'Mike Nichols', 0, '1931-11-06', '#https://de.wikipedia.org/wiki/Mike_Nichols#'),
('NoEp', 'Nora Ephron', 1, '1941-05-19', '#https://de.wikipedia.org/wiki/Nora_Ephron#'),
('NoJewi', 'Norman Jewison', 0, '1926-07-21', '#https://de.wikipedia.org/wiki/Norman_Jewison#'),
('OlStone', 'Oliver Stone', 0, '1946-09-15', '#https://de.wikipedia.org/wiki/Oliver_Stone#'),
('OrWelles', 'Orson Welles', 0, '1915-05-06', '#https://de.wikipedia.org/wiki/Orson_Welles#'),
('PaJenkin', 'Patty Jenkins', 1, '1971-07-24', '#https://de.wikipedia.org/wiki/Patty_Jenkins#'),
('PaVerho', 'Paul Verhoven', 0, '1938-07-18', '#https://de.wikipedia.org/wiki/Paul_Verhoeven_(Regisseur,_1938)#'),
('PeJacksn', 'Peter Jackson', 0, '1961-10-31', '#https://de.wikipedia.org/wiki/Peter_Jackson#'),
('QqTarant', 'Quentin Tarantino', 0, '1963-03-27', '#https://de.wikipedia.org/wiki/Quentin_Tarantino#'),
('RiAttten', 'Richard Attenborough', 0, '1923-08-29', '#https://de.wikipedia.org/wiki/Richard_Attenborough#'),
('RiScott', 'Ridley Scott', 0, '1937-11-30', '#https://de.wikipedia.org/wiki/Ridley_Scott#'),
('RoAltmn', 'Robert Altman', 0, '1925-02-20', '#https://de.wikipedia.org/wiki/Robert_Altman#'),
('RoCorman', 'Roger Corman', 0, '1926-04-05', '#https://de.wikipedia.org/wiki/Roger_Corman#'),
('RoEmme', 'Roland Emmerich', 0, '1955-11-10', '#https://de.wikipedia.org/wiki/Roland_Emmerich#'),
('RoHoward', 'Ron Howard', 0, '1954-03-01', '#https://de.wikipedia.org/wiki/Ron_Howard#'),
('RoPolan', 'Roman Pola?ski', 0, '1933-08-18', '#https://de.wikipedia.org/wiki/Roman_Pola%C5%84ski#'),
('RoRorgz', 'Robert Rodriguez', 0, '1968-06-20', '#https://de.wikipedia.org/wiki/Robert_Rodriguez#'),
('RoZeme', 'Robert Zemeckis', 0, '1952-05-14', '#https://de.wikipedia.org/wiki/Robert_Zemeckis#'),
('SaRaimi', 'Sam Raimi', 0, '1959-10-23', '#https://de.wikipedia.org/wiki/Sam_Raimi#'),
('SeLeone', 'Sergio Leone', 0, '1929-01-03', '#https://de.wikipedia.org/wiki/Sergio_Leone#'),
('SoCopp', 'Sofia Coppola', 1, '1971-05-14', '#https://de.wikipedia.org/wiki/Sofia_Coppola#'),
('StKing', 'Stephen King', 0, '1947-09-21', 'https://de.wikipedia.org/wiki/Stephen_King#https://de.wikipedia.org/wiki/Stephen_King#'),
('StKubr', 'Stanley Kubrick', 0, '1928-07-26', '#https://de.wikipedia.org/wiki/Stanley_Kubrick#'),
('StLee', 'Stan Lee', 0, '1922-12-28', '#https://de.wikipedia.org/wiki/Stan_Lee#'),
('StSodb', 'Steven Soderbergh', 0, '1963-01-14', '#https://de.wikipedia.org/wiki/Steven_Soderbergh#'),
('StSpiel', 'Steven Spielberg', 0, '1946-12-18', '#https://de.wikipedia.org/wiki/Steven_Spielberg#'),
('SyPolla', 'Sydney Pollack', 0, '1934-07-01', '#https://de.wikipedia.org/wiki/Sydney_Pollack#'),
('ThHarb', 'Thea von Harbou', 1, '1888-12-27', '#https://de.wikipedia.org/wiki/Thea_von_Harbou#'),
('TiBurton', 'Tim Burton', 0, '1958-08-25', '#https://de.wikipedia.org/wiki/Tim_Burton#'),
('WaDisney', 'Walt Disney', 0, '1901-12-05', '#https://de.wikipedia.org/wiki/Walt_Disney#'),
('WiWyler', 'William Wyler', 0, '1902-07-01', '#https://de.wikipedia.org/wiki/William_Wyler#'),
('WoAllen', 'Woody Allen', 0, '1935-12-01', '#https://de.wikipedia.org/wiki/Woody_Allen#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_person`
--
ALTER TABLE `z25_person`
  ADD PRIMARY KEY (`kcPerson`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
