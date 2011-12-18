<?php 

abstract class Gasbox_Migration extends Migration{
  public function __construct(){
    parent::__construct();
  }
}

class Gasbox_Prodotti_Migration extends Gasbox_Migration{
  public function __construct(){
    parent::construct();
    $this->description = "Importa i prodotti da un file CSV";
    $columns = array(
      0 => array('codice' => 'Codice del prodotto'),
      1 => array('denominazione'=> 'Denominazione del prodotto'),
      2 => array('formato' => 'Formato della confezione'),
      3 => array('produttore' => 'Produttore'),
      4 => array('note' => 'Note'),
      6 => array('confezioni' => 'Numero pezzi per confezioni'),
      7 => array('prezzo' => 'Prezzo'),
    );
    $this->source = new MigrateSourceCSV(
      $path, 
      $csvcolumns, 
      array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('prodotto');
    $this->map = new MigrateSQLMap(
      $this->machine_name, 
      array(), // $source_key, 
      MigrateDestination::getKeySchema());
    
    $this->addFieldMapping('field_code', 'codice');
    $this->addFieldMapping('title', 'denominazione');
    $this->addFieldMapping('field_code', 'codice');
    $this->addFieldMapping('field_formato_confezione', 'formato');
    $this->addFieldMapping('field_produttore', 'produttore');
    $this->addFieldMapping('field_note', 'note');
    $this->addFieldMapping('field_confezione', 'confezioni');
    $this->addFieldMapping('field_prezzo', 'prezzo');
    
    
  }
}