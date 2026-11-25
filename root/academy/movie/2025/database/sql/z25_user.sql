-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 28, 2026 at 09:24 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `z25_zeus`
--

-- --------------------------------------------------------

--
-- Table structure for table `z25_user`
--

CREATE TABLE `z25_user` (
  `kiUser` smallint(6) NOT NULL,
  `sUsr` varchar(8) NOT NULL,
  `sPwd` varchar(8) NOT NULL,
  `sPwd_crypt` varchar(60) DEFAULT NULL,
  `sName` varchar(40) NOT NULL COMMENT 'Benutzer',
  `sEmail` varchar(60) NOT NULL,
  `tBirthday` date DEFAULT NULL,
  `eGrp` enum('eUsr','eEdt','eMan','eAdm') DEFAULT NULL,
  `iAuth` smallint(4) DEFAULT NULL,
  `tTime` timestamp NULL DEFAULT NULL,
  `bActive` enum('False','True') NOT NULL,
  `bEnabled` enum('False','True') NOT NULL,
  `bConfirmed` enum('False','True') NOT NULL COMMENT 'confirmed'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `z25_user`
--

INSERT INTO `z25_user` (`kiUser`, `sUsr`, `sPwd`, `sPwd_crypt`, `sName`, `sEmail`, `tBirthday`, `eGrp`, `iAuth`, `tTime`, `bActive`, `bEnabled`, `bConfirmed`) VALUES
(1, 'adm', 'adm', '*3DCFB64FE0CB05D63B9AF64492B5CD6269D82EE8', 'Superman', 'adm@my-mib.net', '1902-02-01', 'eAdm', 1234, '2026-01-27 13:28:19', 'True', 'True', 'True'),
(2, 'pha', 'pha', '*EA145A061BABB040934B761D3C1E12B35FB64F81', 'Peter H.', 'pha@my-mib.net', '1964-07-09', 'eMan', 5781, '2026-01-27 08:28:23', 'True', 'True', 'False'),
(3, 'vha', 'vha', '*6DA98D63E50C56301DC03AFADFEE93F748004B6B', 'Viktoryia', 'vha@my-mib.de', '1974-01-08', 'eUsr', 7744, '2016-02-09 14:56:05', 'False', 'True', 'False'),
(24, 'uli', 'uli', '*6ABCC365F2D2AC86139E64FF3F0C453BAD705BC4', 'Ulrich Rößler', 'uli@e-mail.de', '1969-07-05', 'eUsr', 3145, '2026-01-27 13:41:22', 'False', 'True', 'True');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `z25_user`
--
ALTER TABLE `z25_user`
  ADD PRIMARY KEY (`kiUser`),
  ADD UNIQUE KEY `sUsr_2` (`sUsr`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `z25_user`
--
ALTER TABLE `z25_user`
  MODIFY `kiUser` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
