pipeline {
    agent {
        docker {
            image 'rocker/r-rmd'
            args '-u root' 
        }
    }

    stages {
        stage('Build PDF') {
            steps {
                dir('phase1') {
                    sh 'Rscript -e \'rmarkdown::render(\"Phase1.Rmd\")\''
                    archiveArtifacts artifacts: '*', fingerprint: true
                }
            }
        }
    }
}