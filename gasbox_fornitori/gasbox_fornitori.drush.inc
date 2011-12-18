/** 
* Implementation of hook_drush_command(). 
*/  
  
function gasbox_fornitori_drush_command() {  
  
        // callback is the function that will be called when the command is executed  
    $items['load-data-fornitori'] = array(  
        'callback' => 'gasbox_fornitori_load_data_fornitori',  
            'description' => 'Carica le schede dei fornitori',  
            'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,  
    );  
  
    return $items;  
}  

function gasbox_fornitori_load_data_fornitori(){

}