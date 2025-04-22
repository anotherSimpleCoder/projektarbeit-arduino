pipeline {
    agent {
        docker {
            image 'r-base'
            args '-u root' 
        }
    }

    stages {
        stage('Build PDF') {
            dir('phase1') {
                sh 'Rscript -e \'rmarkdown::render(\'Phase1.Rmd\')\''
                archiveArtifacts artifacts: '*', fingerprint: true
            }
        }
    }
}